<<<<<<< HEAD
=======
git submodule init
git submodule update
>>>>>>> 8b13f38c897270853813f46c33c7461b645fb91f
sudo apt-get install -y gcc make xorg libxext-dev libbsd-dev
cd libs/libmlx
./configure
sudo cp libmlx.a /usr/local/lib
sudo cp mlx.h /usr/local/include
