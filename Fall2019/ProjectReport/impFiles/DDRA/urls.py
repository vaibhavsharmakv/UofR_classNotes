from django.contrib import admin
from django.urls import path
from django.conf.urls.static import static 
from django.conf import settings
from DDRA.views import home_view,display_eye


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', home_view),
    path('display/<int:my_id>', display_eye)
]


urlpatterns += static(settings.MEDIA_URL,document_root= settings.MEDIA_ROOT)

