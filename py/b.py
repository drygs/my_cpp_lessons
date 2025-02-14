import pyautogui
import keyboard
import time

time.sleep(3)
def automacao():
    try:
        while True:
            # Exemplo de automação: mover o mouse e clicar
            pyautogui.moveTo(801, 504)
            pyautogui.click()
            pyautogui.click()
            pyautogui.click()
            pyautogui.click()
            pyautogui.click()
            pyautogui.click()
            pyautogui.click()
            pyautogui.click()
            pyautogui.click()
            pyautogui.click()

            time.sleep(0)  # Esperar 2 segundos entre as ações
            
            # Verificar se F6 foi pressionado
            if keyboard.is_pressed('F6'):
                print("F6 pressionado! Parando a automação.")
                break
    except Exception as e:
        print(f"Ocorreu um erro: {e}")

# Executar a automação
automacao()
