const fs = require('fs');

async function readDir(dirs = '.', depth = 0) {
	try {
		for(let i = 0; i < dirs.length; i++) {
			let newDir = fs.readdirSync(dirs[i]);
			for (let j = 0; j < newDir.length; j++) {
				newDir[j] = dirs[i] + "/" + newDir[j];
			}
			if(depth == 0) {
				console.log('\x1b[36m%s\x1b[0m', dirs[i]);
			} else {
				newDir.forEach(d => { 
					process.stdout.write("\x1b[36m" + "*".repeat(depth) + " " + "\x1b[0m");
					console.log(d) 
				});
			}
			newDir = newDir.filter(newDir => fs.lstatSync(newDir).isDirectory() && newDir != '.' );

			readDir(newDir, depth + 1);

		}
	} catch (err) {
		console.log(err);
	}
}
readDir();
