#!/bin/bash
#                                  ┌─────────────────────────────────────────┐
#                                  │         Bash Aliases (PERSONAL)         │
#                                  ├─────────────────────────────────────────┤
#                                  │     https://github.com/cyadehn/.vim     │
#                                  └─────────────────────────────────────────┘
# ┌─────────────────────────┐
# │         General         │
# └─────────────────────────┘
    alias o="open ."
    # Serve live IP
    export LOCAL_IP='ipconfig getifaddr en0'
    alias serve="browser-sync start -s -f . --host $LOCAL_IP --port 9000"
    alias rex="open 'https://rextester.com/'"
# ┌─────────────────────────┐
# │        Edit/Git         │
# └─────────────────────────┘
    alias vim="nvim -v"
    alias cvim="nvim ./*.cs"            
    alias nn="nvim"
    alias gap="git add -p"
    alias st="git status"
    alias com='git commit -m'
    alias clone='git clone'
    alias amend='git commit --amend'
    alias lg="lazygit"
    alias gil="gh issue list"
    alias gi="gh issue view"
# ┌─────────────────────────┐
# │        FRAMEWORKS       │
# └─────────────────────────┘
    alias .b="dotnet build *.csproj"
    alias .r="dotnet run"
    alias .t="dotnet test --verbosity quiet --nologo"
    alias ,c="clang *.c"
# ┌─────────────────────────┐
# │       Directories       │
# └─────────────────────────┘
    alias plroot="cd /Users/christopherdehner/Library/Python/2.7/lib/python/site-packages/powerline"
    alias proj="cd /Users/christopherdehner/Code/projects && n"
    alias poke="cd /Users/christopherdehner/Code/projects/dotnet/PokemonCLI && n"
    alias dld="cd ~/Downloads && n"
    alias vs="cd ~/Projects && n"
    alias rc="cd ~/.dotfiles && n"
    alias ..='cd ..'
    alias ...='cd ..; cd ..'
    alias ....='cd ..; cd ..; cd ..'
# ┌─────────────────────────┐
# │         Terminal        │
# └─────────────────────────┘
    alias q='exit'
    alias c='clr'
    alias h='history'
    alias lsa='ls -a'
    alias lsl='ls -l'
    alias t='time'
    alias k='kill'
    
