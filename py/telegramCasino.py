from telegram import Update, ReplyKeyboardMarkup
from telegram.ext import Application, CommandHandler, MessageHandler, ContextTypes, filters

# Função para iniciar o bot
async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    # Criação do teclado com botões
    keyboard = [["Roleta", "Dices"], ["Slot Machine", "Sair"]]

    reply_markup = ReplyKeyboardMarkup(keyboard, resize_keyboard=True, one_time_keyboard=True)

    # Envia a mensagem com o teclado
    await update.message.reply_text("Escolha um jogo:", reply_markup=reply_markup)

# Função para lidar com as mensagens de texto
async def message_handler(update: Update, context: ContextTypes.DEFAULT_TYPE):
    # Lê a mensagem enviada pelo usuário
    text = update.message.text

    if text == "Roleta":
        await update.message.reply_text("Você escolheu jogar Roleta!")
    elif text == "Dices":
        await update.message.reply_text("Você escolheu jogar Dices!")
    elif text == "Slot Machine":
        await update.message.reply_text("Você escolheu jogar Slot Machine!")
    elif text == "Sair":
        await update.message.reply_text("Até logo!")
    else:
        await update.message.reply_text("Escolha uma opção válida!")

def main():
    TOKEN = ''  # Substitua pelo seu token
    application = Application.builder().token(TOKEN).build()

    # Comandos
    application.add_handler(CommandHandler('start', start))
    application.add_handler(MessageHandler(filters.TEXT & ~filters.COMMAND, message_handler))

    # Inicia o bot
    application.run_polling()

if __name__ == '__main__':
    main()
