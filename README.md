# cpp-prototyping-bazel-template
This is a template for prototyping code with bazel and including gmock and gtest to test the project.

To use:
1. Clone this repo
2. Build with bazel build ...
3. Test with bazel run //test:tests

# Notes on Installing Bazel in WSL2 Ubuntu 20

When I tried installing bazel into WSL2 Ubuntu 20, I ran into some problems. 

Here are notes to work around them:
Installing Bazel on Ubuntu 20 WSL2

First step from the Bazel docs
> sudo apt install curl gnupg
> curl -f https://bazel.build/bazel-release.pub.gpg | sudo apt-key add -
> echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list


Second step:
> sudo apt update && sudo apt install bazel
> sudo apt update && sudo apt full-upgrade
> sudo apt install bazel-1.0.0

If you get an error that tells you the public key is not available:

Err:1 https://storage.googleapis.com/bazel-apt stable InRelease                          
  The following signatures couldn't be verified because the public key is not available: NO_PUBKEY 3D5919B448457EE0

Then receive the keys via:
> sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys {KEY}
i.e.
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 3D5919B448457EE0

If you get further errors like:
Executing: /tmp/apt-key-gpghome.il9kR0iI0U/gpg.1.sh --keyserver keyserver.ubuntu.com --recv-keys 3D5919B448457EE0
gpg: connecting dirmngr at '/tmp/apt-key-gpghome.il9kR0iI0U/S.dirmngr' failed: IPC connect call failed
gpg: keyserver receive failed: No dirmngr

What you could do is to remove gpg and use gnupg.

> sudo apt remove gpg
> sudo apt-get update -y
> sudo apt-get install -y gnupg1 

Then run apt-key again:
> sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 3D5919B448457EE0

Perfomr the steps again to install bazel.

At this point, bazel should now be installed.

> bazel --version
bazel 3.4.1


