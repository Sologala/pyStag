import pyStag as stag
import cv2

det = stag.Detector(15, 7, False)

imgPath = "../00003.png"
grayImg = cv2.imread(imgPath, cv2.IMREAD_GRAYSCALE)
cv2.imshow("img", grayImg)
print("detected markers  Cnt: ", det.detect(grayImg))
print("detected markers's Id: ", det.getIds())
print("detected markers's Coners: ", det.getContours())
