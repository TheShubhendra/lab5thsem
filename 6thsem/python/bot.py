import cv2 as cv

screen = cv.imread("timber.png")
cv.imshow("Image", screen)
cv.waitKey(0)