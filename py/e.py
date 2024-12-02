import keyboard

# Nome do arquivo onde as teclas serão armazenadas
arquivo = "teclas_digitadas.txt"

print(f"Pressione as teclas e elas serão salvas em '{arquivo}' (pressione 'esc' para sair).")

# Abrir o arquivo em modo de escrita
with open(arquivo, "w", encoding="utf-8") as f:
    while True:
        evento = keyboard.read_event()
        if evento.event_type == "down":  # Apenas capturar quando a tecla é pressionada
            if evento.name == "esc":  # Sair do programa ao pressionar 'esc'
                print("\nSaindo...")
                break
            elif len(evento.name) == 1:  # Apenas caracteres únicos como letras e números
                f.write(evento.name)  # Escreve a tecla no arquivo
                f.flush()  # Garante que a escrita seja salva imediatamente
            else:
                f.write(f"[{evento.name}]")  # Para teclas especiais, como 'space', 'enter'
                f.flush()
