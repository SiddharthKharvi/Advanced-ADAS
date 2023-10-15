import numpy as np 
import cv2
import keyboard
import time
import serial
  
cap = cv2.VideoCapture(0)

ser = serial.Serial('COM8', 9600, timeout=0.050)
SM = 'I'

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

        if keyboard.is_pressed("0"):
            if SM == 'I':
                SM = 'A'
                print("Traffic Signal Light Recon Active..!")
                time.sleep(2)

                
            else:
                SM = 'I'
                print("Traffic Signal Light Recon Inactive..!")
                time.sleep(2)

        if SM == 'A':
            b, g, r = cv2.split(img)
            total_red_intensity = r.sum()
            total_green_intensity = g.sum()

            if total_red_intensity > total_green_intensity:
                print ("Red Signal")
                time.sleep(1)80
                ser.write(bytes('S', 'utf-8'))
                
            else:
                print ("Green Signal")

        
    cap.release() 
    cv2.destroyAllWindows() 
else: 
    print("Alert ! Camera disconnected")
    
