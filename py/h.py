import random
from telegram import InlineKeyboardButton, InlineKeyboardMarkup
from telegram.ext import Application, CommandHandler, CallbackQueryHandler

# Função que roda o jogo de roleta
async def roleta(update, context):
    keyboard = [
        [InlineKeyboardButton("Vermelho", callback_data="red"),
         InlineKeyboardButton("Preto", callback_data="black")],
        [InlineKeyboardButton("Números 1-18", callback_data="1-18"),
         InlineKeyboardButton("Números 19-36", callback_data="19-36")],
    ]
    reply_markup = InlineKeyboardMarkup(keyboard)
    await update.message.reply_text("Aposte na roleta! Escolha uma opção:", reply_markup=reply_markup)

# Função que resolve a roleta
async def resultado_roleta(update, context):
    query = update.callback_query
    aposta = query.data

    # Simula o número sorteado na roleta
    numero_sorteado = random.randint(0, 36)
    cor = "vermelho" if numero_sorteado % 2 == 0 else "preto"
    faixa = "1-18" if 1 <= numero_sorteado <= 18 else "19-36"

    # Verifica se o jogador ganhou
    if aposta == cor:
        resultado = f"Você apostou em {cor} e ganhou! O número sorteado foi {numero_sorteado} {cor}."
    elif aposta == faixa:
        resultado = f"Você apostou nos números {faixa} e ganhou! O número sorteado foi {numero_sorteado}."
    else:
        resultado = f"Você perdeu! O número sorteado foi {numero_sorteado} {cor}."

    await query.edit_message_text(text=resultado)

# Função para iniciar o bot
async def start(update, context):
    await update.message.reply_text('Bem-vindo ao cassino! Escolha um jogo para começar:')
    await update.message.reply_text('/roleta - Jogue a roleta')

# Função principal para rodar o bot
def main():
    TOKEN = '7807467676:AAH1WH2Wt1g7vPu5DpL3zbNLJh4_Dc7Bf7g'  # Substitua pelo seu token
    application = Application.builder().token(TOKEN).build()

    # Comandos
    application.add_handler(CommandHandler("start", start))
    application.add_handler(CommandHandler("roleta", roleta))

    # Resposta dos jogos
    application.add_handler(CallbackQueryHandler(resultado_roleta))

    # Inicia o bot
    application.run_polling()

if __name__ == '__main__':
    main()
