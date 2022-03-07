import pyStag as stag
import cv2
import numpy as np

det = stag.Detector(15, 7, False)

imgPath = "00003.png"
ori_img = cv2.imread(imgPath)
grayImg = cv2.cvtColor(ori_img, cv2.COLOR_BGR2GRAY)
# cv2.imshow("img", grayImg)
print("detected markers  Cnt: ", det.detect(grayImg))
coners = det.getContours()
ids = det.getIds()
outimg = ori_img
for bbx, id in zip(coners, ids):
    # print(bbx, id)
    outimg = cv2.line(outimg,tuple(map(int,bbx[0])), tuple(map(int,bbx[1])),(255,225,0),5)
    outimg = cv2.line(outimg,tuple(map(int,bbx[1])), tuple(map(int,bbx[2])),(255,225,0),5)
    outimg = cv2.line(outimg,tuple(map(int,bbx[2])), tuple(map(int,bbx[3])),(255,0,225),5)
    outimg = cv2.line(outimg,tuple(map(int,bbx[3])), tuple(map(int,bbx[0])),(255,0,225),5)
    outimg = cv2.putText(outimg, "{}".format(id),tuple(map(int ,bbx[0])), cv2.FONT_HERSHEY_COMPLEX, 3, (0,0,225), 2)

cv2.imwrite("img-res.png", outimg)
print("detected markers's Id: ", det.getIds())
print("detected markers's Coners: ", det.getContours())
print("Detection result has been writed to img-res.png")

