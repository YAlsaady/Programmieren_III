let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Studium/3.Semster/Programmieren_3/Aufgaben/Aufgabe_2/src
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 main.cc
badd +1 ~/Studium/3.Semster/Programmieren_3/Aufgaben/Aufgabe_2/src/lager.cc
badd +1 ~/Studium/3.Semster/Programmieren_3/Aufgaben/Aufgabe_2/src/lager.hh
badd +1 ~/Studium/3.Semster/Programmieren_3/Aufgaben/Aufgabe_2/src/waren.txt
badd +1 ~/Studium/3.Semster/Programmieren_3/Aufgaben/Aufgabe_2/src/Makefile
argglobal
%argdel
$argadd main.cc
edit main.cc
argglobal
balt ~/Studium/3.Semster/Programmieren_3/Aufgaben/Aufgabe_2/src/lager.cc
setlocal fdm=expr
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=20
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 1 - ((0 * winheight(0) + 32) / 64)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
