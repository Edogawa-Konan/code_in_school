import json

import requests
from django.shortcuts import render, redirect
from django.http import HttpResponseRedirect
from django.contrib.auth.decorators import user_passes_test, login_required
from django.contrib.auth.models import User
from django.contrib import auth
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from management.models import MyUser,Book,BorrowInfo,Message
from django.core.urlresolvers import reverse
from management.utils import permission_check,Init
from datetime import datetime,timedelta
from django.utils import timezone



def index(request):
    Init(request.user)
    return redirect('view_book_list',permanent=True)

def signup(request):
    if request.user.is_authenticated():
        return HttpResponseRedirect(reverse('view_book_list'))
    state = None
    if request.method == 'POST':
        password = request.POST.get('password', '')
        repeat_password = request.POST.get('repeat_password', '')
        if password == '' or repeat_password == '':
            state = 'empty'
        elif password != repeat_password:
            state = 'repeat_error'
        else:
            username = request.POST.get('username', '')
            if User.objects.filter(username=username):
                state = 'user_exist'
            else:
                new_user = User.objects.create_user(username=username, password=password,
                                                    email=request.POST.get('email', ''))
                new_user.save()
                new_my_user = MyUser(user=new_user, nickname=request.POST.get('nickname', ''),permission=0)
                new_my_user.save()
                state = 'success'
    content = {
        'active_menu': 'homepage',
        'state': state,
        'user': None,
    }
    return render(request, 'management/signup.html', content)


def login(request):
    if request.user.is_authenticated():
        return HttpResponseRedirect(reverse('view_book_list'))
    state = None
    if request.method == 'POST':
        username = request.POST.get('username', '')
        password = request.POST.get('password', '')
        user = auth.authenticate(username=username, password=password)
        if user is not None:
            auth.login(request, user)
            return HttpResponseRedirect(reverse('view_book_list'))
        else:
            state = 'not_exist_or_password_error'
    content = {
        'active_menu': 'homepage',
        'state': state,
        'user': None
    }
    return render(request, 'management/login.html', content)


def logout(request):
    auth.logout(request)
    return HttpResponseRedirect(reverse('view_book_list'))


@login_required
def set_password(request):
    user = request.user
    state = None
    if request.method == 'POST':
        old_password = request.POST.get('old_password', '')
        new_password = request.POST.get('new_password', '')
        repeat_password = request.POST.get('repeat_password', '')
        if user.check_password(old_password):
            if not new_password:
                state = 'empty'
            elif new_password != repeat_password:
                state = 'repeat_error'
            else:
                user.set_password(new_password)
                user.save()
                state = 'success'
        else:
            state = 'password_error'
    content = {
        'user': user,
        'active_menu': 'homepage',
        'state': state,
    }
    return render(request, 'management/set_password.html', content)


@user_passes_test(permission_check)
def check_message(request):
    timestamp=timezone.now()-timedelta(days=20) #这里需要用timezone而不是datetime，否则会引发异常
    # Message.objects.filter(date__lte=timestamp).delete() #删除20天之前的
    message_list=Message.objects.order_by('-date')
    content={'message_list':message_list,'active_menu': 'check_message'}
    return render(request,'management/check_message.html',content)


@user_passes_test(permission_check)
def clear_message(request):
    Message.objects.all().delete()
    return redirect('check_message')


@user_passes_test(permission_check)
def add_book(request,dic=None):
    user = request.user
    state = None
    if request.method == 'POST':
        N=request.POST.get('number','')
        N=int(N)
        for i in range(N):
            new_book = Book(
                    name=request.POST.get('name', ''),
                    author=request.POST.get('author', ''),
                    category=request.POST.get('category', ''),
                    price=request.POST.get('price', 0),
                    publish_date=request.POST.get('publish_date', ''),
                    ISBN=request.POST.get('ISBN',''),
                    location=request.POST.get('location',''),
                    state=True,
            )
            new_book.save()
            state = 'success'
    content = {
        'user': user,
        'active_menu': 'add_book',
        'state': state,
    }
    return render(request, 'management/add_book.html', content)

def douban(ISBN):
    url = 'https://api.douban.com/v2/book/isbn/:' + str(ISBN)
    try:
        html = requests.request('Get', url, timeout=3)
        html.raise_for_status()
        html.encoding = html.apparent_encoding
        ob=json.loads(html.text)
        return {'ISBN':ISBN,'name':ob['title'],'author':ob['author'][0],'pubdate':ob['pubdate'],'price':ob['price'],'img':ob['images']['large']}
    except requests.HTTPError as e:
        return None


@user_passes_test(permission_check)
def add_book_by_ISBN(request):
    if request.method=='POST':
        ISBN=request.POST.get('ISBN')
        return HttpResponseRedirect(reverse('confirm',args=[ISBN]))
    return render(request,'management/add_book_by_ISBN.html',{'active_menu':'add_book_by_ISBN'})


@user_passes_test(permission_check)
def confirm(request,ISBN):
    Dict=douban(ISBN)
    if request.method=='POST':
        N = request.POST.get('number', '')
        N = int(N)
        for i in range(N):
            new_book = Book(
                name=request.POST.get('name', ''),
                author=request.POST.get('author', ''),
                category=request.POST.get('category', ''),
                price=request.POST.get('price', 0)[:-1],
                publish_date=request.POST.get('publish_date', ''),
                location=request.POST.get('location', ''),
                img=Dict['img'],
                state=True,
            )
            new_book.save()
        return render(request,'management/add_book.html',{'state':'success'})
    return render(request,'management/add_book.html',Dict)





@user_passes_test(permission_check)
def del_book(request):
    book_id=request.GET.get('id')
    item=Book.objects.get(id=book_id)
    state=None

    if item.state==False:
        state='defeat'
    else:
        if request.method == 'POST':
            new_message = Message(bookname=item.name,content=request.POST.get('reason', ''), user=request.user.myuser)
            new_message.save()
            item.delete()
            state='success'

    content = {'state': state}
    return render(request,'management/del_book.html',content)




@user_passes_test(permission_check)
def edit_book(request):
    state=None
    book_id = request.GET.get('id', '')
    item=Book.objects.get(pk=book_id)
    if request.method == 'POST':
        location=request.POST.get('location')
        item.location=location
        item.save()
        state='success'
    content = {'book': item, 'state': state}
    return render(request,'management/edit_book.html',content)




def view_book_list(request):
    user = request.user if request.user.is_authenticated() else None
    category_list = Book.objects.values_list('category', flat=True).distinct()
    query_category = request.GET.get('category', 'all')
    if Book.objects.filter(category=query_category).count() is 0:#如果查不到或者搜索框为空就全检索
        query_category = 'all'
        book_list = Book.objects.all()
    else:
        book_list = Book.objects.filter(category=query_category)

    if request.method == 'POST':
        keyword = request.POST.get('keyword', '')
        book_list = Book.objects.filter(name__contains=keyword)
        query_category = 'all'

    # book_list.order_by('id')
    # assert book_list.ordered==True
    paginator = Paginator(book_list.order_by('id'), 5)
    page = request.GET.get('page')
    try:
        book_list = paginator.page(page)
    except PageNotAnInteger:# If page is not an integer, deliver first page.
        book_list = paginator.page(1)
    except EmptyPage:# If page is out of range (e.g. 9999), deliver last page of results.
        book_list = paginator.page(paginator.num_pages)
    content = {
        'user': user,
        'active_menu': 'view_book',
        'category_list': category_list,
        'query_category': query_category,
        'book_list': book_list,
    }
    return render(request, 'management/view_book_list.html', content)


def detail(request):
    user = request.user if request.user.is_authenticated() else None
    book_id = request.GET.get('id', '')
    if book_id == '':
        return HttpResponseRedirect(reverse('view_book_list'))
    try:
        book = Book.objects.get(pk=book_id)
    except Book.DoesNotExist:
        return HttpResponseRedirect(reverse('view_book_list'))
    content = {
        'user': user,
        'active_menu': 'view_book',
        'book': book,
    }
    return render(request, 'management/detail.html', content)


def borrowe(request):
    content = {'state': None}
    if request.method=='POST':
        book_id=request.POST.get('book_id')
        username=request.POST.get('username')


        u=User.objects.filter(username=username)[0]
        item=Book.objects.filter(pk=book_id)[0]

        borrower = u.myuser

        content['state']='wrong'

        if u==None or item==None:
            content['message']='The book or user name is incorrect'
        elif borrower.balance<100:
            content['message']='Your balance is not enough, you can not borrow books'
        elif item.state==False:
            content['message'] = 'Sorry, the book has been lent!'
        elif BorrowInfo.objects.filter(brower_id=borrower.id).count()==2:
            content['message'] = 'You can borrow up to two at the same time!'
        else:
            delta = timedelta(days=30)
            t = BorrowInfo(brower_id=borrower.id, book_id=book_id, dead_line=timezone.now() + delta)
            t.save()
            b = Book.objects.get(pk=book_id)
            b.state = False
            b.save()
            content['message'] = "Loan success"
            content['state']='success'
        return render(request,'management/borrow.html',content)
    return render(request,'management/borrow.html')



@login_required
def my_library(request):
    user=request.user
    info_list=BorrowInfo.objects.filter(brower_id=user.myuser.id)
    book_list=[]
    for info in info_list:
        book_list.append((Book.objects.get(pk=info.book_id),info.borrow_time,info.dead_line,info.fine))
    content = {
        'book_list': book_list,
        'active_menu': 'my_library'
    }
    return render(request,'management/my_library.html',content)


@user_passes_test(permission_check)
def return_book(request):
    content = {'state': None}
    if request.method=='POST':
        book_id=request.POST.get('book_id')

        t = BorrowInfo.objects.filter(book_id=book_id)
        if t==None:
            content['state']='wrong'
            content['message']='Did not find the book'
        else:
            b=Book.objects.get(pk=int(book_id))
            b.state=True
            b.save()
            t.delete()
            content['message']='Return the book is successful'
            content['state']='success'
        return render(request,'management/return_book.html',content)
    return render(request,'management/return_book.html',content)




@user_passes_test(permission_check)
def check_user(request):
    user_list=MyUser.objects.filter(permission__lte=1).order_by('nickname')
    content={'user_list':user_list,'active_menu':'check_user'}
    return render(request,'management/check_user.html',content)



@user_passes_test(permission_check)
def edit_user(request,user_pk):
    item=MyUser.objects.get(pk=user_pk)
    state=None
    if request.method=='POST':
        username=request.POST.get('username')
        nickname=request.POST.get('nickname')
        email=request.POST.get('email')
        recharge=request.POST.get('recharge')
        # state=request.POST.get('state')

        item.balance+=int(recharge)
        item.user.username=username
        item.nickname=nickname
        item.user.email=email

        if item.balance>=100:
            item.permission=1

        # if state=='activate':
        #     item.permission=1
        # else:
        #     item.permission=0
        item.save()
        state='success'
    content={'user':item,'state':state}
    return render(request,'management/edit_user.html',content)



@user_passes_test(permission_check)
def del_user(request):
    user_pk=request.GET.get('user_id')
    item=MyUser.objects.get(pk=user_pk)
    item.user.delete() #别忘记删除User表的表项
    item.delete()
    return HttpResponseRedirect(reverse('check_user'))



@user_passes_test(permission_check)
def add_img(request):
    user = request.user
    state = None
    if request.method == 'POST':
        try:
            new_img = Img(
                    name=request.POST.get('name', ''),
                    img=request.FILES.get('img', ''),
                    book=Book.objects.get(pk=request.POST.get('book', ''))
            )
            new_img.save()
        except Book.DoesNotExist as e:
            state = 'error'
            print(e)
        else:
            state = 'success'
    content = {
        'user': user,
        'state': state,
        'book_list': Book.objects.all().distinct(),
        'active_menu': 'add_img',
    }
    return render(request, 'management/add_img.html', content)

@user_passes_test(permission_check)
def modify_fine(request):
    content={'state':None}
    if request.method=='POST':
        unit=request.POST.get('unit')
        with open("E:\\code_in_school\\LibraryManagement\\config.json", 'w') as f:
            json.dump({'unit':unit},f)
        content['state']='success'
    else:
        with open("E:\\code_in_school\\LibraryManagement\\config.json", 'r') as f:
            unit = json.load(f)['unit']
            content['unit'] = unit
    return render(request,'management/modify_fine.html',content)







