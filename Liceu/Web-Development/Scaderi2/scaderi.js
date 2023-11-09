const express = require('express') // pentru express web framework | Aplicatia este un server web.
//var fs = require('fs') // pentru a putea accesa fisiere
const Database = require('better-sqlite3') // pentru a folosi baze de date sqlite
//var cndv = require('./cndv.js') // pentru a folosi functia noastra, care pregateste tabelul

const app = express() // obiectul aplicatie
const port = 3000 // portul la care asculta aplicatia

const db = new Database('./scaderi.db', { verbose: console.log }) // | optiunea prezinta interogarile 

//var start = fs.readFileSync('./start.html') // Citim fisierul, care va fi inceputul stringului raspuns.
//var end = `</body>` // Sfarsitul stringului raspuns.

// Ca sa preia ce s-a trimis cu post din formular. Daca nu punem optiunea, primim mesaj "deprecated".
//app.use(express.urlencoded({ extended: true }))
//app.use(express.static(__dirname)) // Ca sa transmita fisierul css.
app.use(express.json()); // Parse JSON bodies (as sent by API clients)

app.get('/s', function (req, res) {
    res.sendFile('scaderi.html', { root: __dirname })
})

// post = se transmit date din browser
// parametri:
// adresa 
// req = ceea ce se transmite, un obiect complex
app.post('/termeni', (req, res) => { 
    console.log(req.body);
    // var descazut = req.body.descazut; // variabile care retin ceea ce am primit din formular
    // var scazator = req.body.scazator;

    var stmt = db.prepare(`
        INSERT INTO tari
        VALUES (?, ?, ?, ?)
    `) // Pregatim instructiunea.
    stmt.run(denumire, continent, capitala, locuitori); // Se executa instructiunea, folosind parametri.

    // stmt = db.prepare(`
    //     SELECT *
    //     FROM tari
    // `) // Pregatim instructiunea.
    // var tari = stmt.all() // Se executa instructiunea.
    // var t = cndv.tabel(tari) // Rezultatul returnat este un vector de linii. Obtinem codul HTML al tabelului.
    // t = t + `<p>${__dirname}<\p>`   

    // res.send(start + t + end) // Concatenam si transmitem browserului.
    // res.end()
    // return
})

app.listen(port, () => { 
    var d = new Date()
    h = d.getHours()
    m = d.getMinutes()
    s = d.getSeconds()
    console.log(`${h}:${m}:${s}`)
    console.log(`Aplicatia asteapta la http://localhost:${port}`)
})
