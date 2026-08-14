export ZSH="$HOME/.oh-my-zsh"

export ZSH_THEME=lambda

source "$ZSH/oh-my-zsh.sh"

export NOW=`date '+%F_%H:%M:%S'`;

sudo apt update -y
sudo apt upgrade -y

clear

echo "+==========================================================+"
echo "Welcome ${USER}! to Ne.app OS."
echo "The Time is $NOW$."
uname -a
echo "+==========================================================+"
