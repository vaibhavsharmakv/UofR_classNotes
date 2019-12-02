from django import forms
from django.db import models

from .models import eye_images 


class eye_images_form(forms.ModelForm):
 
    class Meta:
        model = eye_images
        fields = [
            'image',
        ]
    
