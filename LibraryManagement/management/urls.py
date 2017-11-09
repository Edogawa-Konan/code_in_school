from django.conf.urls import url
from management import views

urlpatterns = [
    url(r'^$', views.index, name='homepage'),
    url(r'^signup/$', views.signup, name='signup'),
    url(r'^login/$', views.login, name='login'),
    url(r'^logout/$', views.logout, name='logout'),
    url(r'^set_password/$', views.set_password, name='set_password'),
    url(r'^add_book/$', views.add_book, name='add_book'),
    url(r'^add_book_by_ISBN/$',views.add_book_by_ISBN,name='add_book_by_ISBN'),
    url(r'^add_img/$', views.add_img, name='add_img'),
    url(r'^borrowe/$',views.borrowe,name='borrowe'),
    url(r'^return_book/$',views.return_book,name='return_book'),
    url(r'^confirm/(\d+)$',views.confirm,name='confirm'),
    url(r'^check_message/$',views.check_message,name='check_message'),
    url(r'^check_message/clear_message/$',views.clear_message,name='clear_message'),
    url(r'^check_user/$',views.check_user,name='check_user'),
    url(r'^check_user/(\d+)$',views.edit_user,name='edit_user'),
    url(r"^check_user/del_user$",views.del_user,name='del_user'),
    url(r'^my_library/$',views.my_library,name='my_library'),
    url(r'^view_book_list/$', views.view_book_list, name='view_book_list'),
    url(r'^view_book/detail/$', views.detail, name='detail'),
    url(r'^view_book/detail/del_book$', views.del_book, name='del_book'),
    url(r'^view_book/detail/edit_book$',views.edit_book,name='edit_book'),
]
