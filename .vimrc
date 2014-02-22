  
set nocompatible

"MANDA PATHOGEN

execute pathogen#infect()
call pathogen#helptags()
call pathogen#incubate()
"
"PLUGINS I USE
"
" YankRing.vim
" │checksyntax_vim
" │indentLine
" │nerdcommenter
" │nerdtree
" │numbers
" │powerline
" │python-mode
" │supertab
" │syntastic
" │tcomment_vim
" │tlib_vim
" │vim-addon-mw-utils
" │vim-colors-solarized
" │vim-powerline
" │vim-repeat
" │vim-sensible
" │vim-snipmate
" │vim-surround"
" 

"SOLARIZE THEME
let g:solarized_termcolors=256

syntax enable
set background=dark


"MODIFICHE SCRITTURA E SISTEMA

set hidden "FA APRIRE PIù BUFFER SENZA CHIUDERE PRECEDENTE

let mapleader=","

set noswapfile
set nowb
set nobackup
set expandtab
set nowrap        " don't wrap lines
set tabstop=4    " a tab is four spaces
set backspace=indent,eol,start " allow backspacing over everything in insert mode
set autoindent    " always set autoindenting on
set copyindent    " copy the previous indentation on autoindenting
set number        " always show line numbers
set shiftwidth=4  " number of spaces to use for autoindenting
set shiftround    " use multiple of shiftwidth when indenting with '<' and '>'
set showmatch     " set show matching parenthesis
set ignorecase    " ignore case when searching
set smartcase     " ignore case if search pattern is all lowercase,
                  "   case-sensitive otherwise
set smarttab      " insert tabs on the start of a line according to
                  "    shiftwidth, not tabstop
set hlsearch      " highlight search terms
set incsearch     " show search matches as you type
set history=1000         " remember more commands and search history
set undolevels=1000      " use many muchos levels of undo
set title                " change the terminal's title
set visualbell           " don't beep
set noerrorbells         " don't beep
filetype plugin indent on
" set list
"set listchars=tab:....,trail:.,extends:#,nbsp:.
" set list lcs=tab:\|\
"set listchars+=tab:┊\  
autocmd filetype html,xml set listchars-=tab:>.
set pastetoggle=<C-V>
set mouse=a
set wildmode=list:longest,full
set wildmenu
set showmatch

let hlstate=0
nnoremap <F4> :if (hlstate == 0) \| nohlsearch \| else \| set hlsearch \| endif \| let hlstate=1-hlstate<cr>

"
"
"PYTHON
"
"
let $PYTHONHOME='/System/Library/Frameworks/Python.framework/Versions/Current'
let g:pymode_rope_lookup_project = 0
let g:pymode_rope_autoimport = 0
autocmd filetype py set foldmethod=indent

