
# Test case

## Index
---
[1. built-in](#built-in)<br/>
[2. heredoc](#heredoc)<br/>

---
### built-in
---
```sh
# echo
echo asdf					# asdf\n
echo -n asdf asdf sadf		# asdf asdf sadf (no nl)
echo						# \n
echo -n						# (no nl)
echo -nnnnn					# (no nl)
echo -nasdf qwer			# -nasdf qwer
echo -n -n -n -n -nnnn sdf	# sdf (no nl)

# cd
cd							# move to home
unset HOME && cd			# bash: cd: HOME NOT SET
cd path						# move by CDPATH and display path
							# if none, move by absolute path

cd path/path				# move by absolute/relative path
cd -						# move by OLDPWD, display OLDPWD
cd NON						# bash: cd: No such file or directory
cd path path path			# move by first arg
cd path NON					# non error
cd NON path					# error, no dir change

# pwd
pwd							# display curr path
pwd arg						# diplay curr path, non err

# export
export						# display envp list with format
export a					# set a with no value
export a=1					# set a with value 1
export a=					# set a with value ""
export a=1 b=2 c=3			# set a with 1, b with 2, c with 3
export 1=a					# bash: export: `1=a': not a valid identifier
export (=d					# bash: export: `(=a': not a valid identifier
export åß=a					# bash: export: `åß=a': not a valid identifier

# unset
unset						# do nothing
unset a						# unset a
unset a=1					# bash: unset: `a=1': not a valid identifier
unset a=					# bash: unset: `a=': not a valid identifier
unset a b c					# unset a b c

# env
env							# display envp, except null value

# exit
exit						# exit with curr exit status
exit 1						# exit with 1
exit 1 2 3					# minishell: exit: too many arguments, no exit
exit a						# minishell: exit: a: numeric argument required, exit 255
exit a b c					# minishell: exit: a: numeric argument required, exit 255
exit 1 a b					# minishell: exit: too many arguments, no exit
exit a 1 2					# minishell: exit: a: numeric argument required, exit 255
exit LONG_MAX + 1L			# minishell: exit: arg: numeric argument required, exit 255
exit LONG_MIN - 1L			# minishell: exit: arg: numeric argument required, exit 255
exit -1						# exit with -1
exit +1						# exit with +1
exit -----1					# minishell: exit: arg: numeric argument required, exit 255
```
---
### heredoc
---
```sh
<<eof << eof << eof			# execute heredoc three times
<< eof |||					# syntax err, execute heredoc, end with exit status 258
<< |||						# 
<< 'eof'					#
> $USER						#

<< eof						#
> $USER						#
> "$USER"					#
> '$USER'					#
> $"USER"					#
> $US"ER					#
> $USERA					#
> "$USER-RA"				#

<< $USER					#

```