
from django.utils import timezone
from management.models import BorrowInfo


def permission_check(user):
    if user.is_authenticated():
        return user.myuser.permission > 1
    else:
        return False



def Init(user):
    if user!=None:
        borrow_info=BorrowInfo.objects.filter(brower_id=user.myuser.id)
        total_fine=0
        for info in borrow_info:
            difference=(info.dead_line-timezone.now()).days #相差的天数
            if difference>30 and difference<=40:
                info.fine=-(difference-30) #31~40每天1块钱
            elif difference>40 and difference<=50:
                info.fine=-(difference-40)*3+10
            else:
                info.fine=-(difference-50)*5+10+30
            total_fine+=info.fine
        user.myuser.balance+=total_fine
        if user.myuser.balance < 100:  # 登录检测，钱不够滚蛋
            user.myuser.permission = 0







