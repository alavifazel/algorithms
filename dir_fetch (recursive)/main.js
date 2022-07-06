const {log} = require('console');
const fs = require('fs');

async function readDir(dirs = ['.'], dirListLength = 3, depth = 0) {
	try {
        dirs = dirs.slice(0, dirListLength);
		for(let i = 0; i < dirs.length; i++) {
			let newDir = fs.readdirSync(dirs[i]);
			for (let j = 0; j < newDir.length; j++) {
				newDir[j] = dirs[i] + "/" + newDir[j];
			}
			if(depth == 0) {
				console.log('\x1b[36m%s\x1b[0m', dirs[i]);
			} else {
				for(let j = 0; j < Math.min(newDir.length, dirListLength); j++) {
					process.stdout.write("\x1b[36m" + "*".repeat(depth) + " " + "\x1b[0m");
					console.log(newDir[j]);
                    log(j)
				}
			}
			newDir = newDir.filter(newDir => fs.lstatSync(newDir).isDirectory() && newDir != '.' );

			readDir(newDir, dirListLength, depth + 1);

		}
	} catch (err) {
		console.log(err);
	}
}

let args = process.argv.slice(2);
if(args.length > 2) {
    console.info("Usage: node ./<script> <directory>='.' <dirListLength>=3");
} else {
    readDir(args[0], args[1]);
}
