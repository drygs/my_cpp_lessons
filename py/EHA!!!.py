import turtle

# Configuração da tela
win = turtle.Screen()
win.title("Ping Pong")
win.bgcolor("black")
win.setup(width=800, height=600)
win.tracer(0)

# Raquete da esquerda
left_paddle = turtle.Turtle()
left_paddle.speed(0)
left_paddle.shape("square")
left_paddle.color("white")
left_paddle.shapesize(stretch_wid=6, stretch_len=1)
left_paddle.penup()
left_paddle.goto(-350, 0)

# Raquete da direita
right_paddle = turtle.Turtle()
right_paddle.speed(0)
right_paddle.shape("square")
right_paddle.color("white")
right_paddle.shapesize(stretch_wid=6, stretch_len=1)
right_paddle.penup()
right_paddle.goto(350, 0)

# Bola
ball = turtle.Turtle()
ball.speed(15)
ball.shape("circle")
ball.color("white")
ball.penup()
ball.goto(0, 0)
ball.dx = 0.2
ball.dy = -0.2

# Movimentos das raquetes
def left_paddle_up():
    y = left_paddle.ycor()
    if y < 250:
        left_paddle.sety(y + 20)

def left_paddle_down():
    y = left_paddle.ycor()
    if y > -240:
        left_paddle.sety(y - 20)

def right_paddle_up():
    y = right_paddle.ycor()
    if y < 250:
        right_paddle.sety(y + 20)

def right_paddle_down():
    y = right_paddle.ycor()
    if y > -240:
        right_paddle.sety(y - 20)

# Controles do teclado
win.listen()
win.onkeypress(left_paddle_up, "w")
win.onkeypress(left_paddle_down, "s")
win.onkeypress(right_paddle_up, "Up")
win.onkeypress(right_paddle_down, "Down")

# Loop principal do jogo
while True:
    win.update()
    
    # Movimento da bola
    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)
    
    # Colisão com as bordas superiores e inferiores
    if ball.ycor() > 290 or ball.ycor() < -290:
        ball.dy *= -1
    
    # Colisão com as raquetes
    if (ball.xcor() > 340 and ball.xcor() < 350 and ball.ycor() < right_paddle.ycor() + 50 and ball.ycor() > right_paddle.ycor() - 50):
        ball.dx *= -1
    if (ball.xcor() < -340 and ball.xcor() > -350 and ball.ycor() < left_paddle.ycor() + 50 and ball.ycor() > left_paddle.ycor() - 50):
        ball.dx *= -1
    
    # Reseta a bola caso saia da tela
    if ball.xcor() > 390 or ball.xcor() < -390:
        ball.goto(0, 0)
        ball.dx *= -1
