export PS1="[\[\e[0;34m\]\u\[\e[0m\]@\h]:\[\e[0;32m\]\w\[\e[m\]\\n\\$ "

export VISUAL=nvim
export EDITOR="$VISUAL"

set () {
	loc=$1
}

source "$HOME/.dotfiles/nvim/plugged/gruvbox/gruvbox_256palette.sh"
# Powerline Prompt
source ~/Library/Python/2.7/lib/python/site-packages/powerline/bindings/bash/powerline.sh

# NNN Plugins
export NNN_FIFO='/tmp/nnn.fifo'
export NNN_PLUG='n:bulknew;f:finder;g:getplugs;v:preview-tui;w:wall'

n ()
{
    # Block nesting of nnn in subshells
    if [ -n $NNNLVL ] && [ "${NNNLVL:-0}" -ge 1 ]; then
        echo "nnn is already running"
        return
    fi

    # The default behaviour is to cd on quit (nnn checks if NNN_TMPFILE is set)
    # To cd on quit only on ^G, remove the "export" as in:
    #     NNN_TMPFILE="${XDG_CONFIG_HOME:-$HOME/.config}/nnn/.lastd"
    # NOTE: NNN_TMPFILE is fixed, should not be modified
    export NNN_TMPFILE="${XDG_CONFIG_HOME:-$HOME/.config}/nnn/.lastd"

    # Unmask ^Q (, ^V etc.) (if required, see `stty -a`) to Quit nnn
    # stty start undef
    # stty stop undef
    # stty lwrap undef
    # stty lnext undef

    nnn "$@" -d

    if [ -f "$NNN_TMPFILE" ]; then
            . "$NNN_TMPFILE"
            rm -f "$NNN_TMPFILE" > /dev/null
    fi
}
