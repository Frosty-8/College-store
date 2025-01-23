document.getElementById("convertBtn").addEventListener("click", async () => {
    const fileInput = document.getElementById("wordFile");
    const status = document.getElementById("status");

    if (!fileInput.files.length) {
        status.textContent = "Please select one or more Word files.";
        return;
    }

    status.textContent = "Processing files...";
    const files = fileInput.files;

    for (let i = 0; i < files.length; i++) {
        const file = files[i];
        try {
            await convertWordToPDF(file, i + 1); // Pass the file and index
        } catch (error) {
            console.error(`Error processing file ${file.name}:`, error);
        }
    }

    status.textContent = `Processed ${files.length} files. All PDFs downloaded.`;
});

async function convertWordToPDF(file, index) {
    return new Promise((resolve, reject) => {
        const reader = new FileReader();

        reader.onload = async function (e) {
            try {
                const content = e.target.result;
                const JSZip = window.JSZip; // Ensure JSZip is globally available
                const zip = await JSZip.loadAsync(content); // Correctly initialize JSZip
                const doc = new window.docxtemplater().loadZip(zip); // Load the .docx file
                const text = doc.getFullText();

                // Convert text content to PDF
                const { jsPDF } = window.jspdf;
                const pdf = new jsPDF();
                pdf.text(text, 10, 10);

                // Trigger download
                const fileName = `output_${index}.pdf`;
                pdf.save(fileName); // Save the PDF with a unique name
                console.log(`File downloaded: ${fileName}`);
                resolve();
            } catch (error) {
                console.error(`Error converting file: ${file.name}`, error);
                reject(error);
            }
        };

        reader.onerror = function () {
            console.error("Error reading file:", reader.error);
            reject(reader.error);
        };

        reader.readAsArrayBuffer(file); // Read the file as an ArrayBuffer
    });
}
