# Generated by Django 2.0.7 on 2019-11-19 04:47

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('DDRA', '0012_remove_eye_images_uid'),
    ]

    operations = [
        migrations.AlterField(
            model_name='eye_images',
            name='image',
            field=models.ImageField(default='empty.jpg', upload_to='datasetsImages/'),
        ),
    ]
