import * as vscode from 'vscode';

export class Data {

    public ip : string = "";
    public host : string = "";
    public password : string = "";
    public user : string = "";
    public remoto : any = "";
    public cont : number = 1;
    private pass : string = "9450476b384b32d8ad8b758e76c98a69";

    private encriptar(x : string) {
        let crypto = require('crypto');
        let hashPwd = crypto.createHash('md5').update(x).digest('hex');
        return hashPwd;
    }

    public verificar (){

        if (this.ip == "127.0.0.1" && this.host == "8080"){
            if (this.encriptar(this.password) == this.pass){
                return true;
            }
        }else{
            return false;
        }

    }

    public funcion(box : vscode.InputBox) {

        if (this.cont == 1){
            this.remoto = box.value; 
            this.cont ++;
            this.asignar();       
            box.hide();
        }else if (this.cont == 2){
            this.ip = box.value; 
            this.cont ++;      
            box.hide(); 
            this.showBoxText("💻Inserte puerto💻");
        }else if (this.cont == 3){
            this.host = box.value; 
            this.cont ++;       
            box.hide(); 
            this.showBoxText("👨‍Contraseña👨‍");
        }else if (this.cont == 4){
            this.password = box.value; 
            this.cont ++;      
            box.hide(); 
            this.showBoxText("🚀Inserte usuario🚀");
        }else if (this.cont == 5){
            this.user = box.value; 
            this.cont ++;      
            box.hide();
        }

    }

    public showBoxText (title : string){ 

        let box = vscode.window.createInputBox();

        box.title = title;
        let first = this.cont;

        box.onDidAccept(()=>this.funcion(box));
        box.show();
    }

    public asignar (){

        if (this.remoto == "si" || this.remoto == "Si"){
            this.showBoxText("👨‍💻Inserte IP👨‍💻");
        }

    }
}