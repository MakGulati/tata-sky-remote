import serial
import time
import tkinter as tk 
ArduinoSerial=serial.Serial('/dev/cu.usbmodem14311',9600)
time.sleep(2)
def close_window (): 
    root.destroy()
    root.mainloop()
    import sys
    sys.exit("exiting")
def sel():
    selection = "You selected the option " + str(var.get())
    label.config(text = selection)
    v = str(var.get())
    if (v == '5'): #if the value is 5
        ArduinoSerial.write('5'.encode()) #send 5
        print ("Power")
        time.sleep(1)
        
    if (v == '1'): #if the value is 1
        ArduinoSerial.write('1'.encode()) #send 1
        print ("Mute")
        time.sleep(1)
    if (v == '2'): #if the value is 2
        ArduinoSerial.write('2'.encode()) #send 2
        print ("Guide")
        time.sleep(1)
    if (v == '3'): #if the value is 3
        ArduinoSerial.write('3'.encode()) #send 3
        print ("Vol+")
        time.sleep(1)

    if (v == '4'): #if the value is 4
        ArduinoSerial.write('4'.encode()) #send 4
        print ("Vol-")
        time.sleep(1)
        
    if (v == '6'): #if the value is 6
        ArduinoSerial.write('6'.encode()) #send 6
        print ("back")
        time.sleep(1)
    if (v == '7'): #if the value is 7
        ArduinoSerial.write('7'.encode()) #send 7
        print ("left")
        time.sleep(1)
    if (v == '8'): #if the value is 8
        ArduinoSerial.write('8'.encode()) #send 8
        print ("right")
        time.sleep(1)
    if (v == '9'): #if the value is 9
        ArduinoSerial.write('9'.encode()) #send 9
        print ("up")
        time.sleep(1)
    if (v == '10'): #if the value is 10
        ArduinoSerial.write('a'.encode()) #send a
        print ("down")
        time.sleep(1)
    if (v == '11'): #if the value is 11
        ArduinoSerial.write('b'.encode()) #send b
        print ("Select")
        time.sleep(1)        

root = tk.Tk()
root.title('Tata Sky')
frame=tk.Frame(root)
frame.pack()
var = tk.IntVar()

tk.Radiobutton(root, text="Power", variable=var, value=5, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="Mute", variable=var, value=1, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="Guide", variable=var, value=2, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="Vol+", variable=var, value=3, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="Vol- ", variable=var, value=4, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="back", variable=var, value=6, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="left", variable=var, value=7, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="right", variable=var, value=8, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="up", variable=var, value=9, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="down", variable=var, value=10, command=sel).pack(anchor=tk.W)
tk.Radiobutton(root, text="Select", variable=var, value=11, command=sel).pack(anchor=tk.W)
button = tk.Button (frame, text = "Good-bye.", command = close_window).pack(anchor=tk.W)
label = tk.Label(root)
label.pack()
root.mainloop()






     
