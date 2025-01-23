// script.js
document.addEventListener("DOMContentLoaded", () => {
    const imageInput = document.getElementById("imageInput");
    const preview = document.getElementById("preview");
    const generatePdfButton = document.getElementById("generatePdfButton");
    let images = [];
  
    imageInput.addEventListener("change", (event) => {
      const files = Array.from(event.target.files);
      if (files.length + images.length > 500) {
        alert("You can upload a maximum of 500 images!");
        return;
      }
 
      files.forEach((file) => {
        if (file.type.startsWith("image/")) {
          const reader = new FileReader();
          reader.onload = (e) => {
            const img = document.createElement("img");
            img.src = e.target.result;
            preview.appendChild(img);
            images.push(e.target.result);
          };
          reader.readAsDataURL(file);
        }
      });
    });
  
    generatePdfButton.addEventListener("click", async () => {
      if (images.length === 0) {
        alert("Please upload images first.");
        return;
      }
  
      const { jsPDF } = window.jspdf;
      const pdf = new jsPDF();
  
      for (let i = 0; i < images.length; i++) {
        if (i > 0) pdf.addPage();
        const img = images[i];
        pdf.addImage(img, "JPEG", 10, 10, 180, 260);
      }
  
      pdf.save("images.pdf");
    });
  });


  // const fs = require('fs');
  // const { PDFDocument } = require('pdf-lib');
  // const mammoth = require('mammoth');
  
  // async function pdfToWord(pdfPath, wordPath) {
  //     // Load the PDF
  //     const pdfBytes = fs.readFileSync(pdfPath);
  //     const pdfDoc = await PDFDocument.load(pdfBytes);
  
  //     // Extract text from PDF
  //     let text = '';
  //     for (let i = 0; i < pdfDoc.getPageCount(); i++) {
  //         const page = pdfDoc.getPage(i);
  //         text += await page.getTextContent().then(content => {
  //             return content.items.map(item => item.str).join(' ');
  //         });
  //     }
  
  //     // Convert text to Word document
  //     const wordBuffer = await mammoth.convertToHtml({ text: text });
  //     fs.writeFileSync(wordPath, wordBuffer.value);
  //     console.log(`Converted PDF to Word: ${wordPath}`);
  // }
  
  // // Usage
  // pdfToWord('input.pdf', 'output.docx');

  // const fs = require('fs');
  // const officegen = require('officegen');
  // const { PDFDocument } = require('pdf-lib');
  
  // async function wordToPdf(wordPath, pdfPath) {
  //     // Load the Word document
  //     const docx = officegen('docx');
      
  //     // Read the Word file (you may need to use a library that can read .docx files)
  //     const wordBuffer = fs.readFileSync(wordPath);
  
  //     // Create a PDF document
  //     const pdfDoc = await PDFDocument.create();
  //     const page = pdfDoc.addPage([600, 400]);
  
  //     // Add text to the PDF (for simplicity, just adding a placeholder)
  //     page.drawText('This is a placeholder for the Word content.');
  
  //     // Save the PDF
  //     const pdfBytes = await pdfDoc.save();
  //     fs.writeFileSync(pdfPath, pdfBytes);
  //     console.log(`Converted Word to PDF: ${pdfPath}`);
  // }
  
  // // Usage
  // wordToPdf('input.docx', 'output.pdf');


  // npm install pdf-lib mammoth

  // npm install officegen pdf-lib