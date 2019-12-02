import fastai
from fastai import *
from fastai.vision import *
from PIL import Image
import os
from io import BytesIO
from typing import List, Dict, Union, ByteString, Any
import base64
import csv, gc, gzip, os, pickle, shutil, warnings, yaml
import sys, subprocess , io


from joblib import *

import requests



#Variables
BASE_DIR = "/Users/kayvee/machineLearningCNN/detetcting-diabetic-ratinpathy-using-AI/Venv/DDR/"
model_path = "/Users/kayvee/machineLearningCNN/detetcting-diabetic-ratinpathy-using-AI/Venv/DDR/models/"
#path=os.path.join(BASE_DIR,'models')
#print(path)

def load_model(path=".", model_name="export.pkl"):
    path = 'models'
    learn = load_learner(model_path, file=model_name)
    #learn = load_learner(model_path,"export.pkl")
    return learn.to_fp32()
    
model = load_model('models')


def get_Image(imgName: str)->Image:
    dir = os.path.join(BASE_DIR,"datasetsImages/")
    image = Image.open(os.path.join(dir,imgName))
    return image

def load_image_bytes(raw_bytes: ByteString) -> Image:
    img = open_image(BytesIO(raw_bytes))
    return img


def predict(img, n: int = 3) -> Dict[str, Union[str, List]]:
    with open('models/DR_classes.txt') as f:
        classes = f.read().split(',')
    pred_class, pred_idx, outputs = model.predict(img)
    pred_probs = outputs / sum(outputs)
    pred_probs = pred_probs.tolist()
    predictions = []
    print(str(pred_class))
    for image_class, output, prob in zip(model.data.classes, outputs.tolist(), pred_probs):
        output = round(output, 1)
        prob = round(prob, 2)
        predictions.append(
            {"class": classes[image_class], "output": output, "prob": prob}
        )

    predictions = sorted(predictions, key=lambda x: x["output"], reverse=True)
    predictions = predictions[0:n]
    return {"class": str(pred_class), "predictions": predictions}







def predict_result(iurl: str)-> Dict[str, Union[str, List]]:
  
    #opening image
    imgUrl = iurl
    image = get_Image(imgUrl)

    #coverting to bytes
    im_resize = image.resize((500, 500))
    buf = io.BytesIO()
    im_resize.save(buf, format='JPEG')
    byte_im = buf.getvalue()
    image = load_image_bytes(byte_im)

    #processing image through model
    res = predict(image)

    #return model results
    return res










