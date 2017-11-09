import os
from django.utils import timezone
from management.models import BorrowInfo,MyUser
import json


def permission_check(user):
    if user.is_authenticated():
        return user.myuser.permission > 1
    else:
        return False



def Init(user):
    if os.path.exists("E:\\code_in_school\\LibraryManagement\\config.json"):
        with open("E:\\code_in_school\\LibraryManagement\\config.json",'r') as f:
            unit=json.load(f)['unit']
        if user!=None and user.myuser.permission<=1:
            borrow_info=BorrowInfo.objects.filter(brower_id=user.myuser.id)
            total_fine=0
            for info in borrow_info:
                difference=(info.dead_line-timezone.now()).days #相差的天数
                info.fine=-(difference)*unit
                total_fine+=info.fine
            user.myuser.balance+=total_fine
            if user.myuser.balance < 100:  # 登录检测，钱不够滚蛋
                user.myuser.permission = 0
            user.myuser.save()

        elif user.myuser.permission>1:
            borrow_info=BorrowInfo.objects.all()
            for info in borrow_info:
                difference = (info.dead_line - timezone.now()).days  # 相差的天数
                info.fine = -(difference) * unit
                person=MyUser.objects.get(pk=info.brower_id)
                person.balance+=info.fine
                if person.balance<100:
                    person.permission=0
                person.save()










