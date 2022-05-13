#https://hackernoon.com/automating-whatsapp-web-with-alright-and-python-e6i935a1
from time import sleep
from alright import WhatsApp
messenger = WhatsApp()

number= "+91XXXXXXXXXX"
message = "Test Message here"


messenger.find_user(number)
sleep(15)
messages = list(message.split())
for message in messages:  
    messenger.send_message(message)
    sleep(5)
sleep(60*10)