# Birdtray-MATE

Birdtray-MATE is a system tray new mail notification for Thunderbird, specifically tailored and optimized for the MATE desktop environment. It is a fork of the original [Birdtray](https://github.com/gyunaev/birdtray).

Birdtray-MATE is free software and does not require Thunderbird extensions. It checks the unread e-mail status directly by reading the Thunderbird email mork database.

## MATE-Specific Enhancements & Features

This fork includes several improvements designed to enhance the experience on MATE and other traditional X11 desktop environments:

- **MATE Panel Integration**: Dynamically scales to fit the MATE panel perfectly, regardless of panel height (e.g., 24px, 36px, 45px, 75px).
- **Proportional Padding**: Applies a precise 16% padding margin to ensure the tray icon matches the aesthetic sizing of modern tray icons (like KeePassXC or Nextcloud) instead of stretching awkwardly.
- **Dynamic Unread Count**: Font sizes and outline borders of the unread counter are dynamically scaled based on panel height, preventing fuzzy red blobs on small icons and overflow on large panels.
- **Single-Click Minimization**: Left-clicking the tray icon toggles Thunderbird's visibility seamlessly, bypassing X11 focus-stealing prevention.
- **Compositor Refresh Fix**: Fixes icon flashing/blinking on the MATE notification applet by explicitly forcing XEmbed repaints when the opacity or icon updates.
- **Direct Thunderbird Actions**: Includes "New Event" and "New Task" directly in the tray icon's context menu.
- **File Watcher Auto-Recovery**: More robust `.msf` file monitoring that automatically recovers if files are temporarily deleted or locked by Thunderbird folder repairs.

## Standard Features Inherited from Birdtray

- Shows the unread email counter in the Thunderbird system tray icon;
- Optionally can animate the Thunderbird system tray icon if new mail is received;
- You can snooze new mail notifications for a specific time period;
- You can configure which accounts you want to check for unread emails on;
- You can choose different font colors for different email accounts.
- Can launch Thunderbird when Birdtray starts, and terminate it when Birdtray quits (configurable).
- You can choose the tray icon, or use Thunderbird original icon;
- Can monitor that Thunderbird is running, and indicate it if you accidentally closed it;
- Has configurable "New Email" functionality, allowing pre-configured email templates.

## Building

To build Birdtray-MATE from source, you would need the following components:

- A C++ compiler
- Cmake
- Qt 6.2 or higher;
- libX11-devel
- libxtst-devel (required for X11 key injection for New Event/Task)

To build, please do the following:

```shell script
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

Launch the `./birdtray` executable from the build directory.

## Installation

Run `cmake --build . --target install` to install Birdtray-MATE.
On Unix systems, you can configure the install location by running
`cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ..` before the command above.

## Usage

Once started, Birdtray-MATE will show the Thunderbird icon in system tray.

Right-click on this icon, and click Settings. Go to Monitoring tab and select the Thunderbird MSF file for the mailbox you'd like to monitor. 

### Configuration File Location
*Birdtray-MATE configuration is stored on a per-user basis:*

#### Linux Package Installation
`$HOME/.config/birdtray-config.json`

## Submitting bugs and feature requests

Please use the Github issue tracker of this repository. Please attach the log output, if relevant. It could be obtained from Settings -> Advanced (tab) -> Show Log Window (button) -> copy-paste from it into bug report.

## Author and license

Birdtray was originally written by George Yunaev. Birdtray-MATE is maintained as a dedicated fork by Andrew DeFaria (Andrew@DeFaria.com).
It is licensed under the GPLv3 license.
