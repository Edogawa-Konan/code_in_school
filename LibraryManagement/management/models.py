from django.db import models
from django.contrib.auth.models import User


class MyUser(models.Model):
    user = models.OneToOneField(User)
    nickname = models.CharField(max_length=16)
    permission = models.IntegerField(default=1)
    balance=models.IntegerField(default=0)

    def __str__(self):
        return self.user.username


class Book(models.Model):
    name = models.CharField(max_length=128)
    price = models.FloatField()
    author = models.CharField(max_length=128)
    publish_date = models.DateField()
    category = models.CharField(max_length=128)
    location = models.CharField(max_length=128)
    state=models.BooleanField() #是否在馆
    ISBN=models.CharField(max_length=128)
    img=models.URLField(max_length=128,default=None)

    class META:
        ordering = ['name']

    def __str__(self):
        return self.name



# class Img(models.Model):
#     name = models.CharField(max_length=128,default='封面')
#     img = models.ImageField(upload_to='image/%Y/%m/%d/') #关键字参数设置上传路径和文件名
#     book = models.ForeignKey(Book,on_delete=models.CASCADE) #外码，参考Book
#
#     class META:
#         ordering = ['name']  #根据name这一field name进行排序，可以添加多个，就分级排序喽
#
#     def __str__(self):
#         return self.name


#记录图书借阅情况
class BorrowInfo(models.Model):
    brower_id =models.IntegerField()
    book_id= models.IntegerField()
    borrow_time=models.DateTimeField(auto_now=True)
    fine=models.IntegerField(default=0)
    dead_line=models.DateTimeField()



class Message(models.Model):
    date=models.DateTimeField(auto_now=True)
    user=models.ForeignKey(MyUser,on_delete=models.CASCADE)
    content=models.CharField(max_length=128)
    bookname=models.CharField(max_length=128)

    class META:
        ordering=['data']



