import pywhatkit
#import pyautogui as pg
#import time
#import keyboard as k


number = "+91XXXXXXXXXX" #String

hour = 20 #integer
minute = 33
sendin = 20
close = True
closein = 40

message = "Test Message Here"  #String
messages = list(message.split())

for message in messages:
    pywhatkit.sendwhatmsg(number,message,hour,minute,sendin,close,closein)
    
    """
    time.sleep(2)
    pg.click(1050,950)
    time.sleep(2)
    for j in range(10):
        pg.press('tab')
    pg.press('enter')
    """

    minute+=1
    if minute==60:
        hour+=1
        hour%=24
        minute = 0

