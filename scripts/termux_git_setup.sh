#!/data/data/com.termux/files/usr/bin/bash
set -e
pkg update -y
pkg install -y git nano
echo "Termux pronto para editar e enviar o projeto ao GitHub."
echo "Entre na pasta POBRE_360 e execute:"
echo "git init"
echo "git add ."
echo 'git commit -m "Inicio do POBRE 360"'
echo "Depois crie um repositório vazio no GitHub e adicione o remote indicado pelo GitHub."
