import keyboard
import pyautogui
import time
import threading

# Função para pressionar "W" continuamente
def press_w():
    while True:
        if keyboard.is_pressed('esc'):  # Para encerrar o script ao pressionar ESC
            print("Encerrando...")
            break
        keyboard.press_and_release('w')
        time.sleep(0.1)  # Ajuste a frequência da pressão de "W" aqui

# Função para clicar continuamente
def click_mouse():
    while True:
        if keyboard.is_pressed('esc'):  # Para encerrar o script ao pressionar ESC
            break
        pyautogui.click()
        time.sleep(0.1)  # Ajuste a frequência dos cliques aqui

# Criar threads para rodar as duas funções simultaneamente
thread_w = threading.Thread(target=press_w)
thread_click = threading.Thread(target=click_mouse)

thread_w.start()
thread_click.start()

# Esperar as threads terminarem
thread_w.join()
thread_click.join()
