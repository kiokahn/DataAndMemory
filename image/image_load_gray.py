import cv2
 
# 이미지 읽기
img = cv2.imread('/Users/kiokahn/source/opencv/the starry night_gray.bmp', cv2.IMREAD_GRAYSCALE)
 
# 이미지 화면에 표시
cv2.imshow('the starry night', img)
cv2.waitKey(0)
# 이미지 윈도우 삭제
cv2.destroyAllWindows()
