import os
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
    with open("config.json", 'r') as f:
        source=json.load(f)
    unit = int(source['unit'])
    stamp = datetime.strptime(source['time'], '%Y-%m-%d %H:%M:%S')  # 上次更新时间

    current = datetime.now()
    time_delta = current - stamp  # 距离上一次更新的时间


    if time_delta.days >= 1:
        with open(os.path.abspath("config.json"), 'w') as f:
            json.dump({'unit': unit, 'time': datetime.now()}, f, cls=DateTimeEncoder)

        borrow_info=BorrowInfo.objects.all()
        for info in borrow_info:
            if info.dead_line < current:
                info.fine -= unit * (current - info.dead_line).days if info.dead_line > stamp else unit * (
                current - stamp).days
                person = MyUser.objects.get(pk=info.brower_id)
                person.balance += info.fine
                if person.balance < 100:
                    person.permission = 0
                person.save()
                info.save()
