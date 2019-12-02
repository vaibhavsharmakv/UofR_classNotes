from django.db import models
import uuid

# Create your models here.

class eye_images(models.Model): 
    image = models.ImageField(upload_to= 'datasetsImages/')

    def get_absolute_url(self):
        return reverse("model_detail", kwargs={"pk": self.pk})
    
    
    



