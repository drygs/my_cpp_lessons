import pyautogui
import time
import keyboard


time.sleep(1)
pyautogui.moveTo(895, 1050)
pyautogui.click()
time.sleep(2)
pyautogui.moveTo(220, 64)
pyautogui.click()
time.sleep(0.2)
pyautogui.write("https://web.whatsapp.com/")
pyautogui.press("Enter")
time.sleep(10)
pyautogui.moveTo(262, 352)
pyautogui.click()
time.sleep(0.5)
pyautogui.moveTo(963, 951)
pyautogui.click()
time.sleep(2)

for i in range(1000):
    time.sleep(0.2)
    
    pyautogui.write("WOMP WOMP")
    pyautogui.press("Enter")
    if keyboard.is_pressed('F6'):
        print("F6 pressionado! Parando a automação.")
        break
    time.sleep(0.05)
    



    

