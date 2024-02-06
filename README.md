# LIGHT

### Why:

We're not trying to reinvent the wheel... This is more meant to be a proof of concept and integrated package management suite for *our* programs. We won't force anyone to use it. We want to have the ability to expand and grow in our own way.

---

### Planned Features:

* [ ] Template for integrating packages into the LIGHT repositories.
* [ ] Home/Default repository with a RESTful API.
* [ ] Easy versioning scheme with both binary *and* source support.
* [ ] Front end program `light` with support for a good amount of systems.
* [ ] Caching of packages (binary only).
* [ ] Debug logging.

---

### Dependancies:

- `opencxx-cli >= 0.0.1`
- `jsoncpp >= 1.9.4`
- `libcurl >= 8.5.0`

### How to install/compile:

1. Ensure dependencies are installed.
2. Copy the git repository locally:
   1. `git clone https://github.com/hurbIndustries/LIGHT.git`
   2. `cd LIGHT`
3. Use provided script `./install.sh` for easy installation.
4. Configuration files are available in `/etc/light/conf.json`

---

### How to contribute:

Please feel free to open a pull request! We will be actively watching and helping to maintain as we can. Please note that this repository is mainly for the clientside program. The API/Repo side program can be located at `hurbIndustries/LIGHT-API`. Please follow these guidelines:

- Bug reports:
  - Please be clear and concise, Post log files (if available).
  - Print system info and package versions for compilation so we can help recreate the issue.
- Bug fixes:
  - Please report the bugs patched in your version, Along with any extra code tweaks made.
  - Please reference the bug issue (if applicable).
  - Please use camelCase.
  - Feel free to comment where you fixed and how you did it!
- Feature Requests/Additions:
  - Please use camelCase.
  - Feel free to add your name to the contributor list at the top of the files.
  - Comment as necessary, We want to be able to read.
  - Don't be discouraged if it's not accepted. You're welcome to fork LIGHT for any reason.

---

### Where to find us:

Discord - https://discord.gg/5ud2zGVC.

*Made with love*
*Copyright 2024 - hurbIndustries*
*Originally written by JPD*
