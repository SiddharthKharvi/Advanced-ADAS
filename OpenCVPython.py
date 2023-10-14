import numpy as np 
import cv2
import keyboard
import time
import serial
  
cap = cv2.VideoCapture(0)
ser = serial.Serial('COM8', 9600, timeout=0.050)


while(cap.isOpened()): 
      
    while True: 
          
        ret, img = cap.read() 
        cv2.imshow('img', img) 
        if cv2.waitKey(30) & 0xff == ord('q'): 
            break
        
        ## NAVIGATION
        if keyboard.is_pressed("8"):
            print("F")
            ser.write(bytes('F', 'utf-8'))

        if keyboard.is_pressed("2"):
            print("B")
            ser.write(bytes('B', 'utf-8'))
            
        if keyboard.is_pressed("4"):
            print("L")
            ser.write(bytes('R', 'utf-8'))

        if keyboard.is_pressed("6"):
            print("R")
            ser.write(bytes('L', 'utf-8'))

        if keyboard.is_pressed("5"):
            print("S")
            ser.write(bytes('S', 'utf-8'))

        
            
    cap.release() 
    cv2.destroyAllWindows() 
else: 
    print("Alert ! Camera disconnected")
    
