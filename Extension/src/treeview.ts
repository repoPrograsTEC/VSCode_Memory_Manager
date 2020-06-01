import * as vscode from 'vscode';

export class TreeDataProvider implements vscode.TreeDataProvider<TreeItem> {

	private _onDidChangeTreeData: vscode.EventEmitter<TreeItem | undefined> = new vscode.EventEmitter<TreeItem | undefined>();
  	readonly onDidChangeTreeData: vscode.Event<TreeItem | undefined> = this._onDidChangeTreeData.event;

	data: TreeItem[];
  
	constructor() {
	  this.data = [];
	  
	}
  

	addData(element: TreeItem){
		
		this.data.push(element);

	}


	


	getTreeItem(element: TreeItem): vscode.TreeItem|Thenable<vscode.TreeItem> {
	  return element;
	}
  
	getChildren(element?: TreeItem|undefined): vscode.ProviderResult<TreeItem[]> {
	  if (element === undefined) {
		return this.data;
	  }
	  return element.children;
	}


	refresh(): void {


		this._onDidChangeTreeData.fire();		

		let folderPath = vscode.workspace.rootPath;
		let path = folderPath + '/cmake-build-debug/List.json';
		
		let fs = require('fs');

		fs.readFile(path, 'utf8', (err : any, json : any) => {
			if (err) {
				console.log("File read failed:", err);
				return;
			}

			let data = JSON.parse(json);
			data.Lista.forEach((element:any) => {
								
						this.addData(new TreeItem("ID: " + String(element.ID),[
							new TreeItem(String("Valor: " +  element.Valor)),
							new TreeItem(String("Tipo de dato: " + element.Tipodedato)),
							new TreeItem(String("Memoria: " + element.Direccionmemoria)),
							new TreeItem(String("Referencias: " + element.Referencias))
						]));
					});
    	});
	}
  }
  
  export class TreeItem extends vscode.TreeItem {
	children: TreeItem[]|undefined;
  
	constructor(label: string, children?: TreeItem[]) {
	  super(
		  label,
		  children === undefined ? vscode.TreeItemCollapsibleState.None :
								   vscode.TreeItemCollapsibleState.Expanded);
	  this.children = children;
	}
  }
