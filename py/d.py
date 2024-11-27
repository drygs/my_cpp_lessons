import time
import os

horas = 0
minutos = 0
segundos = 0
tempo = int(input("Digite o tempo em segundos: "))
print("{:02d}:{:02d}:{:02d}".format(horas, minutos, segundos))
for i in range(tempo):
    time.sleep(1)
    segundos += 1
    if segundos == 60:
        segundos = 0
        minutos += 1
    if minutos == 60:
        minutos = 0
        horas += 1
    print("{:02d}:{:02d}:{:02d}".format(horas, minutos, segundos))
