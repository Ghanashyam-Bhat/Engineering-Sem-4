import pywhatkit
#import pyautogui as pg
#import time
#import keyboard as k


recruits = []

hour = 11 #integer
minute = 43
sendin = 20
close = True
closein = 40
 
for j in range(len(recruits)):

    number= "+91"+recruits[j][1]

    message = f"""
    Hello {recruits[j][0]}, this is Ghanashyam Bhat from Embrione club.
    I will be conducting your interview for the role of 'IoT and Robotics Technical Domain Specific Mentor'.
    Your slot for the interview is {recruits[j][2]} {recruits[j][3]} and the interview will be conducted on discord server.

    In case you would like to prepone the interview or change the allocated interview slot, inform me by 3.00 PM today.

    Here is the whatsapp group invite for the ease of communication. For any queries message on the whatsapp group.
    

    Here is the link for interview slot list
    
    """

    minute+=1
    if minute==60:
        hour+=1
        hour%=24
        minute = 0

    pywhatkit.sendwhatmsg(number,message,hour,minute,sendin,close,closein)
        
