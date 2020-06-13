import * as vscode from 'vscode';
import {TreeDataProvider, TreeItem} from './treeview';
import {Data} from './Datos';
//import {TestConection, sendData, recvData} from './Hola';



const ffi = require("ffi-napi");

const library = new ffi.Library("/home/daniel/Desktop/test/asd/VSCode_Memory_Manager/Extension/src/LibVSPtr/libVSPtr.so",{

        "TestConection":[
                "int", ["string", "int"]
        ],
        "sendData": [
                "void", ["string", "string"]
        ],
        "recvData": [
                "void", ["string", "string"]
        ]  
});


var ncp = require('ncp').ncp;


//🦄👨‍💻⚡✨🤘🏻⚛️💻🚀🔥🐛 

function copyuDir(){
	let folderPath = vscode.workspace.rootPath;

	ncp.limit = 16;
 
	ncp('/home/daniel/Desktop/test/asd/VSCode_Memory_Manager/Extension/src/LibVSPtr', folderPath, function (err:any) {
 			if (err) {
   				return console.error(err);
 			}
 		console.log('done!');
	});

}

const datos = new Data();
export function activate(context: vscode.ExtensionContext) {

	copyuDir();

	
	let newData = new TreeDataProvider();
	
	let disposable = vscode.commands.registerCommand('extension.play', () => {

		vscode.window.showInformationMessage('Hola. Atte: DaniGames 🐛');

		datos.showBoxText("🦄¿Desea utilizar servidor remoto? (si / no)🦄");
		
	});
	vscode.window.registerTreeDataProvider('TreeDataProvider', newData);
	vscode.commands.registerCommand('TreeDataProvider.refreshEntry', () =>{
		newData.data =[];
		newData.refresh();	
	});
	
	vscode.commands.registerCommand('TreeDataProvider.load', ()=>{
		
		let folderPath = vscode.workspace.rootPath;
		library.recvData(folderPath + "/List.json", datos.user);

	});
	vscode.commands.registerCommand('TreeDataProvider.save', ()=>{
		
		let folderPath = vscode.workspace.rootPath;
		library.sendData(folderPath + "/List.json", datos.user);

	});

	context.subscriptions.push(disposable);
}

export function deactivate() {}


