# Music-AutoData-Setter

This group of code (which needs to be runs seperately ono by one manually) helps to automatically set the metadata of a song downloaded from Third-Party sites.
It first uses a Music Title String Filter Algorithm which I designed to roughly get the title of the song.
Then it is searched on Spotify Database using its API.
The metadata of best 4 song that matches is fetched. (It also includes a 30 sec sample audio clip of that song).
Now we generate an Audio Fingerprint of our original Song using Google's musicg Library.
We also generate Audio Fingerprint of all the 4 song's clip.
The song whose Fingerprint matches the best is our final selected song.
Its metadata which we fetched earlier are set to out original song !!
