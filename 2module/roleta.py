import random

def roletarussa():
    input("Começar o Jogo:")
    while True:
        bala = random.randint(0, 6)
        if bala == 1:
            print("Bye bye")
            break
        else:
            print("Bala {} Saiu".format(bala))
            dnvRoleta = input("Continuar jogando? [S/N]").lower()
            if dnvRoleta == "n":
                print("Jogo Terminado")
                break
            elif dnvRoleta != "s":
                print("Opção inválida. Por favor, insira 'S' ou 'N'.")

roletarussa()
