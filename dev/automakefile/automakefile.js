import fs from "fs";
import path from "path";

const consts = {
  programName : "ShellArchero";
  repo : path.resolve("../../");
  srcPath : path.resolve(repo, "./src/");
  build : path.resolve(repo, "build/");
  buildWindows : path.resolve(repo, "buildWindows/");
  objects : path.resolve(build, "objects/");
  objectsWindows : path.resolve(buildWindows, "objects/");
  mainc : path.resolve(srcPath, "main.c");
  devFlags : "-Wall";
  linuxFlags : "-lncurses";
  windowsFlags : "";
}
console.log(relativePath(objectsWindows));

function relativePath(pathAbsolute) {
  return path.relative(repo, pathAbsolute);
}

function getFilesByFolder(folderPath) {
  return fs
    .readdirSync(folderPath)
    .map((fileOrFolder) => {
      const buildedPath = path.join(folderPath, fileOrFolder);
      return fs.lstatSync(buildedPath).isDirectory()
        ? getFilesByFolder(buildedPath)
        : buildedPath;
    })
    .filter((pathFiles) => pathFiles.match(/\.c/g));
}
const files = getFilesByFolder(srcPath);

const makefile = `
build:
  mkdir -p ${buildFolder}
  gcc -o3 ${programName} ${mainc} ${linuxFlags}
buildDev:
  mkdir -p ${buildFolder}
  mkdir -p ${objectsFodler}
  ${getFilesByFolder(srcPath).map((pathFile) => {
    return `gcc -c ${pathFile} -o ${path.join(buildFolder, pathFile)}`;
  })}
  gcc -o ${programName}
`;

// console.log(getFilesByFolder(srcPath));
