# clirun

`clirun` is a simple tool to monitor and compile C/C++ files in the specified directory.

## Demo for AUR
[![Clirun Demo](https://github.com/utkarshkrsingh/clirun/assets/72470310/f13cb1b1-0c98-4259-b5b8-907785e2020b)](https://github.com/utkarshkrsingh/clirun/assets/72470310/f13cb1b1-0c98-4259-b5b8-907785e2020b)
## Usage:
Note: Clirun only supports `c` and `cpp` right now.
### Without Path
To monitor and compile in the current working directory:
```bash
clirun    # Will start looking in the current working directory
```
### With Path
To monitor and compile files in a specific directory:
```bash
clirun $HOME/Desktop/    # Will look at this path or directory
```
## Installation:
### For Arch-based distributions, you can install clirun from the `AUR`:
```bash
paru -S clirun    # If you use paru
```
OR
```bash
yay -S clirun    # If you use yay
```
## Demo for Ubuntu
https://github.com/user-attachments/assets/39f06b86-aa7a-4c2f-9cbe-aa4fe0cd3cb7
### To manually install clirun on `Ubuntu`:
1. Clone the repository:
```bash
git clone https://github.com/utkarshkrsingh/clirun.git
cd clirun
```
2. Install build-essential package if it's not already installed:
```bash
sudo apt update
sudo apt install build-essential
```
3. Compile the program:
```bash
make
```
4. Optionally, install it system-wide:
```bash
sudo make install
```
You can now run clirun from any directory.
## Support:

If you encounter any bugs or errors, feel free to fork this repository and modify it to suit your needs. Contributions and feedback are always welcome!
