# MY TERMINAL CONFIGURATION FILE TEMPLATE

## `~/.bashrc`

```bash
# If not running interactively, don't do anything
[[ $- != *i* ]] && return

# Use color differentiation when entering the ls and grep commands.
alias ls='ls --color=auto'
alias grep='grep --color=auto'

# Arch Linux default prompt.
PS1='[\u@\h \W]\$ '

export GPG_TTY=$(tty)    # When entering a password for GPG signing, call the built-in interface of the terminal.
alias ls="eza --icons"    # Quickly display files and directories (with icons; requires eza installation)
alias lsa="eza --icons -la"    # Display all files and directories (with icons; requires eza installation)
alias nv='nvim'    # Abbreviations when launching Neovim.
alias snv='sudo -E nvim'    # ENTER sudo mode in neovim.
alias vconf='nvim ~/.config/nvim/init.lua'    # Quickly edit `~/.config/nvim/init.lua`.
alias bconf='nvim ~/.bashrc'    # Set up a command for quickly editing ~/.bashrc

# Ask before deleting files or folders.
alias rm='rm -i'
alias cp='cp -i'
alias mv='mv -i'

# In the terminal, type `..` to go up one directory level, and type `...` to go up two directory levels.
alias ..='cd ..'
alias ...='cd ../..'

# Quickly submit and push code.
quick_commit() {
    local msg="$1"
    if [ -z "$msg" ]; then
        msg="Update: $(date +'%Y-%m-%d %H:%M:%S')"
    fi

    echo "-> Syncing with github..."
    
    git add . && \
    git commit -m "$msg" && \
    git push

    if [ $? -eq 0 ]; then
        echo "Sync successfully!"
    else
        echo "Sync failed!"
    fi
}
```
