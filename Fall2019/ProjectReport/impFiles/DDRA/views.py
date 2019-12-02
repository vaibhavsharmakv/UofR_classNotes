from django.shortcuts import render, redirect , get_object_or_404
from django.http import HttpResponse,HttpResponseForbidden , Http404

from .models import eye_images
from .forms import eye_images_form
from DDR.settings import BASE_DIR


from django.core.files.storage import FileSystemStorage

from subprocess import run, PIPE 
import sys,os,uuid, asyncio

from .engine import predict_result


def display_eye(request, my_id):


    var ={}
    if request.method == "POST":
        form = eye_images_form(request.POST,request.FILES)
        if form.is_valid():
            new_form = form.save() 
            my_id = str(new_form.id)
            form = eye_images_form()
            return redirect('/display/'+ my_id)

    else :

        obj = get_object_or_404(eye_images, id = my_id)
        var["image"] = obj.image
        var["file_upload"] = True
        var["uploaded"] = ""
        var["obj"] = obj          

        
        image_result = predict_result(str(obj.image))
        
        var["resultObj"] = image_result

        




   
        
    return render(request,"display.html",var)




def home_view(request, *args, **kwargs):
    var = {}
    if request.method == "POST":
        form = eye_images_form(request.POST,request.FILES)
        if form.is_valid():
            new_form = form.save()     
            my_id = str(new_form.id)
            form = eye_images_form()
            return redirect('/display/'+ my_id)
        
    else:
        form = eye_images_form()
        var = {
                'form' : form,
                'uploaded' : "hidden"
           }
    return render(request, "home.html", var)


