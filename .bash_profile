export PS1="[\[\e[0;34m\]\u\[\e[0m\]@\h]:\[\e[0;32m\]\w\[\e[m\]\\n\\$ "

# Setting PATH for Python 3.8
# The original version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.8/bin:${PATH}"
export PATH
export COGNITIVE_SERVICE_KEY=30f02522da984667bde8175421b59569
export VISUAL=nvim
export EDITOR="$VISUAL"

set () {
	loc=$1
}

source ~/.bash_commands
source ~/.bashrc

	# Bind keys to pref & c location
	bind '"\e[24~": "pref\n"'
	bind '"\e[23~": "c\n"'

# Setting PATH for Python 3.9
# The original version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.9/bin:${PATH}"
export PATH
