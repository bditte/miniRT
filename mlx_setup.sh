sudo apt-get install -y gcc make xorg libxext-dev libbsd-dev
cd libs/libmlx
./configure
sudo cp libmlx.a /usr/local/lib
sudo cp mlx.h /usr/local/include
