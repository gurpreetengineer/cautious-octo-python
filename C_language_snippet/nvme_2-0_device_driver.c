#include <linux/module.h>
#include <linux/pci.h>
#include <linux/nvme.h>

static int my_nvme_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
    struct nvme_ctrl *ctrl;
    int result;

    ctrl = nvme_alloc_ctrl(&pdev->dev, NULL);
    if (IS_ERR(ctrl)) {
        return PTR_ERR(ctrl);
    }

    pci_set_drvdata(pdev, ctrl);

    result = nvme_ctrl_init(ctrl);
    if (result) {
        nvme_free_ctrl(ctrl);
        return result;
    }

    result = nvme_register_ctrl(ctrl);
    if (result) {
        nvme_disable_ctrl(ctrl);
        nvme_free_ctrl(ctrl);
        return result;
    }

    return 0;
}

static void my_nvme_remove(struct pci_dev *pdev)
{
    struct nvme_ctrl *ctrl = pci_get_drvdata(pdev);

    nvme_unregister_ctrl(ctrl);
    nvme_disable_ctrl(ctrl);
    nvme_free_ctrl(ctrl);
}

static struct pci_device_id my_nvme_id_table[] = {
    { PCI_DEVICE(0x10EC, 0x8168) },
    { 0 },
};
MODULE_DEVICE_TABLE(pci, my_nvme_id_table);

static struct pci_driver my_nvme_driver = {
    .name     = "my_nvme_driver",
    .id_table = my_nvme_id_table,
    .probe    = my_nvme_probe,
    .remove   = my_nvme_remove,
};

static int __init my_nvme_init(void)
{
    return pci_register_driver(&my_nvme_driver);
}

static void __exit my_nvme_exit(void)
{
    pci_unregister_driver(&my_nvme_driver);
}

module_init(my_nvme_init);
module_exit(my_nvme_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("SSD NVMe 2.0 device driver");
MODULE_LICENSE("GPL");


/**
 * This driver uses the nvme_alloc_ctrl function to allocate a control structure for the SSD, and nvme_ctrl_init to initialize the control structure and detect the presence of the SSD. The nvme_register_ctrl function is then used to register the control structure with the NVMe subsystem, allowing the operating system to communicate with the SSD.
 * 
 * The my_nvme_id_table array defines the vendor and device IDs for the SSD, which are used to match the driver to the SSD during initialization.
 * 
 * The my_nvme_driver structure defines the name of the driver, the ID table, and the probe and remove functions which are called during initialization and removal of the driver.
 * 
 * Finally, the my_nvme_init and my_nvme_exit functions are called during module loading and unloading to register and unregister the driver with the PCI subsystem.
*/
