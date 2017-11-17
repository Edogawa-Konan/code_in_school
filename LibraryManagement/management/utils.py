import os
from django.utils import timezone
from management.models import BorrowInfo,MyUser
import json
from datetime import datetime,date,timedelta


def permission_check(user):
    if user.is_authenticated():
        return user.myuser.permission > 1
    else:
        return False

class DateTimeEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, datetime):
            return obj.strftime('%Y-%m-%d %H:%M:%S')
        elif isinstance(obj, date):
            return obj.strftime('%Y-%m-%d')
        return json.JSONEncoder.default(self, obj)



def Init():
    with open("E:\\code_in_school\\LibraryManagement\\config.json",'r') as f:
        source=json.load(f)
    unit=source['unit']
    stamp=datetime.strptime(source['time'],'%Y-%m-%d %H:%M:%S')

    time_delta=datetime.now()-stamp #距离上一次更新的时间

    # print('time_delta',time_delta)

    if time_delta.days >= 1:
        with open("E:\\code_in_school\\LibraryManagement\\config.json", 'w') as f:
            json.dump({'unit': unit, 'time': stamp+timedelta(days=1)}, f, cls=DateTimeEncoder)

        # if user!=None and user.myuser.permission<=1:
        #     borrow_info=BorrowInfo.objects.filter(brower_id=user.myuser.id)
        #     total_fine=0
        #     for info in borrow_info:
        #         difference=(info.dead_line-timezone.now()).days #相差的天数
        #         info.fine=-(difference)*unit
        #         total_fine+=info.fine
        #     user.myuser.balance+=total_fine
        #     if user.myuser.balance < 100:  # 登录检测，钱不够滚蛋
        #         user.myuser.permission = 0
        #     user.myuser.save()

        # elif user.myuser.permission>1:
        borrow_info=BorrowInfo.objects.all()
        for info in borrow_info:
            info.fine-=unit
            person=MyUser.objects.get(pk=info.brower_id)
            person.balance+=info.fine
            if person.balance<100:
                person.permission=0
            person.save()










